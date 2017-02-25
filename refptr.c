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
#include "refptr.h"
#include <stdlib.h>

typedef struct {
    int owns;
    size_t size;
    char ptr[];
} refptr_header_t;

#define refptr_header(ref) ((ref == NULL) ? ref : (ref - sizeof(refptr_header_t)))

refptr_t refptr_new(size_t size) {
    refptr_header_t *header;

    header = (refptr_header_t *)malloc(size + sizeof(refptr_header_t));
    if (header) {
        header->owns = 1;
        header->size = size;
        return (refptr_t)header->ptr;
    }
    return NULL;
}

refptr_t refptr_reference(refptr_t ref) {
    refptr_header_t *header = refptr_header(ref);

    if (header) {
        header->owns++;
    }
    return ref;
}

refptr_t refptr_release(refptr_t ref) {
    refptr_header_t *header = refptr_header(ref);

    if (header && header->owns-- <= 1) {
        free(header);
    }
    return REFPTR_INITIALIZER;
}

size_t refptr_size(refptr_t ref) {
    refptr_header_t *header = refptr_header(ref);

    return header == NULL ? 0 : header->size;
}
