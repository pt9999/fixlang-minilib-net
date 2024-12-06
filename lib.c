#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// TODO: use getaddrinfo(3)?

// TODO: use hstrerror() and return host lookup error message
int minilib_net_resolve_ipaddress_v4(const char* hostname, uint8_t *out_addr, size_t* io_addr_size)
{
    //printf("hostname=%s\n", hostname);
    struct hostent ret = { 0 };
    struct hostent *result = NULL;
    char buf[65536];
    int h_errnop = 0;
    size_t max_addr_size = *io_addr_size;
    size_t addr_size = 0;

    int err = gethostbyname_r(hostname, &ret, buf, sizeof(buf), &result, &h_errnop);
    //printf("err=%d result=%p h_errnop=%d\n", err, result, h_errnop);

    if (err != 0) {
        // TODO: use hstrerror() and return host lookup error message when err == EAGAIN(11)
        herror("herror:");
        return err;
    }
    if (result != NULL) {
        int h_length = result->h_length;
        char** h_addr_list = result->h_addr_list;
        //printf("h_length=%d h_addr_list=%p\n", h_length, h_addr_list);
        for (size_t i = 0; h_addr_list[i] != NULL; i++) {
            uint8_t* addr = h_addr_list[i];
            //printf("h_addr[%lu]=%d.%d.%d.%d\n", i, addr[0], addr[1], addr[2], addr[3]);
            if (addr_size + 3 < max_addr_size) {
                out_addr[addr_size++] = addr[0];
                out_addr[addr_size++] = addr[1];
                out_addr[addr_size++] = addr[2];
                out_addr[addr_size++] = addr[3];
            }
        }
        //printf("buf=%s\n", buf);
    }
    *io_addr_size = addr_size;

    return 0;
}

//--------------------------------------------------------
// sockaddr_in (IPv4)
//--------------------------------------------------------

void minilib_net_sockaddr_in_destroy(struct sockaddr_in* sin)
{
    //fprintf(stderr, "minilib_net_sockaddr_in_destroy: %p\n", sin);
    if (sin != NULL) {
        memset(sin, 0, sizeof(struct sockaddr_in));
        free(sin);
    }
}

struct sockaddr_in* minilib_net_sockaddr_in_create(uint32_t addr, uint16_t port)
{
    struct sockaddr_in* sin = (struct sockaddr_in*) calloc(sizeof(struct sockaddr_in), 1);
    sin->sin_family = AF_INET;
    sin->sin_port = htons(port);
    sin->sin_addr.s_addr = htonl(addr);
    return sin;
}

uint32_t minilib_net_sockaddr_in_get_address(struct sockaddr_in* sin)
{
    assert(sin->sin_family == AF_INET);
    return ntohl(sin->sin_addr.s_addr);
}

uint16_t minilib_net_sockaddr_in_get_port(struct sockaddr_in* sin)
{
    assert(sin->sin_family == AF_INET);
    return ntohs(sin->sin_port);
}

static void _debug_sockaddr_in(const char* label, struct sockaddr* sa)
{
    struct sockaddr_in* sin = (struct sockaddr_in*) sa;
    fprintf(stderr, "%s: addr=%u port=%d\n", label, ntohl(sin->sin_addr.s_addr), ntohs(sin->sin_port));
}

//--------------------------------------------------------

static sa_family_t _get_sa_family(int sockfd)
{
    struct sockaddr addr; 
    socklen_t addrlen = (socklen_t) sizeof(addr);
    int err = getsockname(sockfd, &addr, &addrlen);
    if (err == -1) {
        return (sa_family_t) -1;
    }
    return addr.sa_family;
}

static socklen_t _calc_addrlen(sa_family_t family)
{
    switch(family)
    {
        case AF_INET: 
            return sizeof(struct sockaddr_in);
        default:
            assert("Currently not supported" == NULL);
            return 0;
    }
}

// Creates an internet TCP socket.
int minilib_net_socket_create_ipv4_tcp()
{
    return socket(AF_INET, SOCK_STREAM, 0);
}

int minilib_net_socket_setsockopt_reuseaddr(int sockfd)
{
    int value = 1;
    return setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value));
}

int minilib_net_socket_bind(int sockfd, struct sockaddr* sa)
{
    //_debug_sockaddr_in("bind", sa);
    socklen_t addrlen = _calc_addrlen(sa->sa_family);
    return bind(sockfd, sa, addrlen);
}

int minilib_net_socket_accept(int sockfd, struct sockaddr** out_addr)
{
    sa_family_t family = _get_sa_family(sockfd);
    socklen_t addrlen = _calc_addrlen(family);
    struct sockaddr* addr = (struct sockaddr*) calloc(addrlen, 1);

    int accepted_fd = accept(sockfd, addr, &addrlen);
    if (accepted_fd == -1) {
        free(addr);
        return -1;
    }
    //_debug_sockaddr_in("accepted", addr);
    *out_addr = addr;
    return accepted_fd;
}

int minilib_net_socket_connect(int sockfd, struct sockaddr* sa)
{
    //_debug_sockaddr_in("connect", sa);
    socklen_t addrlen = _calc_addrlen(sa->sa_family);
    return connect(sockfd, sa, addrlen);
}

