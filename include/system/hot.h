#pragma once

extern struct hot_table {
  char const* compile_timestamp;
  char const* compile_directory;
  void (*initialize)();
} HOT_TABLE;
