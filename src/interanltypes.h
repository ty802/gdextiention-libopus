#pragma once
struct string {
  int length;
  char *pointer;
};
struct Vec2 {
  union {
    struct {
      float x;
      float y;
    };
  };
};
