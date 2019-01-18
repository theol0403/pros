#include "kapi.h"
#include "system/hot.h"

__attribute__((section (".hot_table")))
struct hot_table HOT_TABLE = { 0 };

extern char const* _PROS_COMPILE_TIMESTAMP;
extern char const* _PROS_COMPILE_DIRECTORY;
extern void initialize();

__attribute__((section (".hot_init")))
void install_hot_table() {
  printf("Hello world! %p %p\n", &HOT_TABLE, _PROS_COMPILE_TIMESTAMP);
  HOT_TABLE.compile_timestamp = _PROS_COMPILE_TIMESTAMP;
  HOT_TABLE.compile_directory = _PROS_COMPILE_DIRECTORY;
  HOT_TABLE.initialize = initialize;
}

void invoke_install_hot_table() {
  install_hot_table();
}
