#include <iostream>

#include "libaco/aco.h"

void co_func() {
  std::cout << "co_func 0" << std::endl;
  aco_yield();
  std::cout << "co_func 1" << std::endl;
  aco_yield();
  std::cout << "co_func 2" << std::endl;
  aco_exit();
}

int main() {
  std::cout << "hello" << std::endl;

  aco_thread_init(nullptr);
  aco_t* main_co = aco_create(nullptr, nullptr, 0, nullptr, nullptr);

  aco_share_stack_t* sstk = aco_share_stack_new(0);
  aco_t* co = aco_create(main_co, sstk, 0, co_func, nullptr);

  std::cout << "main 0" << std::endl;
  aco_resume(co);
  std::cout << "main 1" << std::endl;
  aco_resume(co);
  std::cout << "main 2" << std::endl;
  aco_resume(co);
  std::cout << "main 3" << std::endl;

  aco_destroy(co);
  aco_share_stack_destroy(sstk);
  aco_destroy(main_co);

  return 0;
}
