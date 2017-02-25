/*
 *  Copyright (c) 2017  seawolflin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef REFPTR_H
#define REFPTR_H
#include <string.h>

typedef void * refptr_t;

#define REFPTR_INITIALIZER NULL

#define refptr_get(ref) (ref)

#ifdef  __cplusplus
extern "C"
{
#endif

/**
 * Malloc a refptr memory.
 * @param size memory size like malloc()
 * @return NULL if fail, or memory address.
 */
refptr_t refptr_new(size_t size);

/**
 * Reference a refptr count.
 * @param ref refptr
 * @return NULL if fail, or memory address.
 */
refptr_t refptr_reference(refptr_t ref);

/**
 * Release a refptr count or memory space like free().
 * @param ref refptr
 * @return NULL
 */
refptr_t refptr_release(refptr_t ref);

/**
 * Get a refptr size @see refptr_new
 * @param ref refptr
 * @return refptr size
 */
size_t refptr_size(refptr_t ref);

#ifdef __cplusplus
}
#endif

#endif /* REFPTR_H */
