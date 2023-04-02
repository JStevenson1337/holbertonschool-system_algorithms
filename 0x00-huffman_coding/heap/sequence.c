#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* a sequence is an object that returns a new value each time it is called  */

struct sequence
{
  int (*next)(void *data);
  void *data;
};

typedef struct sequence *Sequence;

Sequence create_sequence(int (*next)(void *data), void *data)
  {
    Sequence s;

    s = malloc(sizeof(*s));
    assert(s);

    s->next = next;
    s->data = data;

    return (s);
  }

int sequence_next(Sequence s)
  {
    return s->next(s->data);
  }
