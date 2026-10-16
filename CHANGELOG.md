## 0.9.0
### Changed
- fixproj.toml: Bumped `fix_version` to 1.6.0. Depends on minilib-common@0.15.0,
  minilib-text@0.11.0, minilib-binary@0.8.0, minilib-io@0.10.0,
  minilib-xml@0.8.0.
- Minilib.Net.Request: Changed `_STATUS_REASON` to `c_STATUS_REASON`, and `_CONTENT_TYPE_ALIASES` to `c_CONTENT_TYPE_ALIASES`. Refined their document comments as well.

## 0.8.2
### Changed
- Added indirect dependencies.
- Upgraded to minilib-io@0.9.2, minilib-xml@0.7.1, hashmap@2.1.0, asynctask@2.0.1.

## 0.8.1
### Changed
- Merged PR#3 (thanks to tttmmmyyyy san).
  - Enabled multi-threading for this project's own tests.

## 0.8.0
### Changed
- Merged PR#2 (thanks to tttmmmyyyy san).
  - Migrate to the unboxed-Array standard library.
  - fixproj.toml: Bumped `fix_version` to 1.5.0.
- Upgraded to minilib-io@0.9.0, minilib-xml@0.7.0, asynctask@2.0.0.

## 0.7.4
### Changed
- Upgraded to minilib-io@0.8.5, minilib-xml@0.6.4, hashmap@2.0.1.
- Modified some code to remove the deprecation warnings.

## 0.7.3
### Changed
- Upgraded to minilib-io@0.8.4, minilib-xml@0.6.3, hashmap@2.0.0.

## 0.7.2
### Changed
- Removed indirect dependencies.

## 0.7.1
### Changed
- Utilized minilib-common@0.12.3.
- Also depends on minilib-io@0.8.2, minilib-xml@0.6.1.

## 0.7.0
### Changed
- fixproj.toml: Bumped `fix_version` to 1.3.0. Depends on minilib-common@0.12.0, minilib-io@0.8.0, minilib-xml@0.6.0.

## 0.6.5
### Changed
- adopt change of type of Destructor::make
