# refptr
我们在做项目时经常会有一块内存在多处引用，如果直接将指针多处拷贝的话就会出现内存释放之后，其他拷贝指针就成了野指针。通常的做法就是拷贝内存而不是拷贝指针，这样做就会导致内存浪费。

最好的办法就一块内存可以多处引用而不用当心释放后导致野指针的出现，这就需要使用类似Cpp中refptr的功能。

下面是我设计的一个即能实现refptr的功能，又能像正常的指针那样使用。

主要思想是，在通过malloc分配一块内存时多分配sizeof(refptr\_header\_t)大小的空间用来存储引用计数，refptr\_header\_t结构如下所示，用owns统计当前的引用数，当指针被引用时owns加1，引用释放时就减1，直到最后一个引用释放后就释放整个内存块。如果是在多线程中使用时，owns的加1减1必须是原子操作。
```
typedef struct {
    int owns;
    size_t size;
    char ptr[];
} refptr_header_t;
```
由于refptr\_t是一个void \*类型，因此使用起来就跟普通的指针一样，只是把malloc和free用refptr\_new（或refptr\_reference）和refptr\_release代替。
```
typedef void * refptr_t;
```

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
