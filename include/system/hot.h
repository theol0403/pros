#pragma once

struct hot_table {
  char const* compile_timestamp;
  char const* compile_directory;
  void (*initialize)();
  void (*cpp_initialize)();
};

extern struct hot_table* const HOT_TABLE;
