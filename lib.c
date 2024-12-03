#include <netdb.h>
//#include <sys/types.h>
//#include <unistd.h>
//#include <time.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

// TODO: use getaddrinfo(3)?

int minilib_net_resolve_ipaddress_v4(const char* hostname, uint64_t *out_addresses)
{
    printf("hostname=%s\n", hostname);
    struct hostent ret = { 0 };
    struct hostent *result = NULL;
    char buf[65536];
    int h_errnop = 0;

    int err = gethostbyname_r(hostname, &ret, buf, sizeof(buf), &result, &h_errnop);
    printf("err=%d result=%p h_errnop=%d\n", err, result, h_errnop);
    herror("herror:");
    if (err != 0) {
        return err;
    }
    if (result != NULL) {
        int h_length = result->h_length;
        char** h_addr_list = result->h_addr_list;
        printf("h_length=%d h_addr_list=%p\n", h_length, h_addr_list);
        for (int i = 0; h_addr_list[i] != NULL; i++) {
            uint8_t* addr = h_addr_list[i];
            printf("h_addr[%d]=%d.%d.%d.%d\n", i, addr[0], addr[1], addr[2], addr[3]);
        }
        printf("buf=%s\n", buf);
    }

    return 0;
}