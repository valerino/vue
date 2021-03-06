/**
 * @file   CMem.h
 * @Author valerino
 * @date   13/12/2017
 * @brief  memory primitives, part of vuelib
 */
#ifndef PROJECT_CMEM_H
#define PROJECT_CMEM_H

#include <cstddef>
#include <cstdlib>

/** @brief calls delete() and set the pointer to NULL, if the pointer is not NULL */
#define SAFE_DELETE(__x__)                                                     \
  if (__x__) {                                                                 \
    delete __x__;                                                              \
    __x__ = NULL;                                                              \
  }

class CMem {
public:
  /**
   * allocator wrapper
   * @param s size to be allocated
   * @return pointer to zeroed allocated memory to be freed with CMem::free()
   */
  static void *alloc(size_t s) { return calloc(1, s); }

  /**
   * free wrapper
   * @param p pointer allocated with CMem::alloc(). It's ok to pass NULL.
   * @return
   */
  static void free(void *p) {
    if (p) {
      ::free(p);
    }
  }

  /**
   * realloc wrapper
   * @param p pointer to an already allocated block of memory (with CMem::alloc())
   * @param s new size
   * @return pointer to new memory block (original is freed or extended). if NULL is returned, original pointer is untouched
   */
  static void *realloc(void *p, size_t s) { return ::realloc(p, s); }
};

#endif // PROJECT_CMEMORY_H
