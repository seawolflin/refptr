# refptr
reference pointer

#example
```
 int main(void) {
    refptr_t a = refptr_new(10);
    printf("a size %d\n", refptr_size(a));
    refptr_t aref = refptr_reference(a);
    printf("a %p, aref %p\n", a, aref);
    printf("aref size %d\n", refptr_size(aref));
    a = refptr_release(a);
    printf("a %p, aref %p\n", a, aref);
    printf("aref size %d\n", refptr_size(aref));
    aref = refptr_release(aref);
    return 0;
 }
```
