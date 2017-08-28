#include <stdio.h>

typedef long Align; /* for alignment to long boundary */
struct header { /* block header */
    struct header *next; /* next block if on free list */
    unsigned size; /* size of this block */
};
typedef struct header Header;

static Header base; /* empty list to get started */
static Header *freep = NULL; /* start of free list */
/* malloc: general-purpose storage allocator */
void memoryDetails()
{
  Header *pCur = freep;

  printf("base/free: %8X/%8X => ", &base, freep);
  if (pCur)
  {
    printf("[%8X %4d %8X] -> ", pCur, pCur->size, pCur->next);
    pCur = pCur->next;
  }
  while(pCur && pCur != freep)
  {
    printf("[%8X %4d %8X] -> ", pCur, pCur->size, pCur->next);
    pCur = pCur->next;
  }
  printf("\n");
}

void *Malloc(unsigned nbytes)
{
  Header *p, *prevp;
  Header *morecore(unsigned);
  unsigned nunits;

  nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;
  if ((prevp = freep) == NULL) { /* no free list yet */
    base.next = freep = prevp = &base;
    base.size = 0;
  }
  for (p = prevp->next; ; prevp = p, p = p->next) {
    if (p->size >= nunits) { /* big enough */
      if (p->size == nunits) /* exactly */
        prevp->next = p->next;
      else { /* allocate tail end */
        p->size -= nunits;
        p += p->size;
        p->size = nunits;
      }
      freep = prevp;
      memoryDetails();
      return (void *)(p+1);
    }
    if (p == freep) /* wrapped around free list */
      if ((p = morecore(nunits)) == NULL)
        return NULL; /* none left */
  }
}

#define NALLOC 1024 /* minimum #units to request */
/* morecore: ask system for more memory */

/* free: put block ap in free list */
void Free(void *ap) {
  Header *bp, *p;
  bp = (Header *)ap - 1; /* point to block header */
  for (p = freep; !(bp > p && bp < p->next); p = p->next)
    if (p >= p->next && (bp > p || bp < p->next))
      break; /* freed block at start or end of arena */
  if (bp + bp->size == p->next) {
    bp->size += p->next->size;
    bp->next = p->next->next;
  } else
    bp->next = p->next; /* new free block -> free block */

  if (p + p->size == bp) {
    p->size += bp->size;
    p->next = bp->next;
  } else
    p->next = bp; /* free block -> new free block */
  freep = p;
  memoryDetails();
}

Header *morecore(unsigned nu)
{

  char *cp, *sbrk(int);
  Header *up;

  if (nu < NALLOC)
    nu = NALLOC;

  cp = sbrk(nu * sizeof(Header));

  if (cp == (char *) -1) /* no space at all */
    return NULL;

  up = (Header *) cp;
  up->size = nu;
  Free((void *)(up+1));

  return freep;
}

int main()
{
  int *ptr1 = (int *)Malloc(1000*8);
  printf("%X\n", ptr1);

  int *ptr2 = (int *)Malloc(1001*8);
  printf("%X\n", ptr2);

  int *ptr3 = (int *)Malloc(1002*8);
  printf("%X\n", ptr3);

  int *ptr4 = (int *)Malloc(20*8);
  printf("%X\n", ptr4);
  Free(ptr4);
}
