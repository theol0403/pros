#include "kapi.h"
#include "system/hot.h"

struct hot_table __HOT_TABLE = { 0 };
struct hot_table* HOT_TABLE = &__HOT_TABLE;

extern char const* _PROS_COMPILE_TIMESTAMP;
extern char const* _PROS_COMPILE_DIRECTORY;
extern void initialize();

__attribute__((section (".hot_init")))
void install_hot_table() {
  printf("%s %p %p\n", __FUNCTION__, (void*)HOT_TABLE, (void*)_PROS_COMPILE_TIMESTAMP);
  HOT_TABLE->compile_timestamp = _PROS_COMPILE_TIMESTAMP;
  HOT_TABLE->compile_directory = _PROS_COMPILE_DIRECTORY;
  HOT_TABLE->initialize = initialize;
}

void invoke_install_hot_table() {
  printf("%s %p\n", __FUNCTION__, (void*)install_hot_table);
  install_hot_table();
}
