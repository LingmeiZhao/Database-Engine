#include "BPlusTree.h"

// to create nodes
BplusTree_t *init() {
  int i;
  np = new BplusTree_t;
  np->d = new int[6];
  np->child_ptr = new BplusTree_t *[7];
  np->l = true;
  np->n = 0;
  for (i = 0; i < 7; i++) {
    np->child_ptr[i] = NULL;
  }
  return np;
}

// traverse tree
void traverse(BplusTree_t *p) {
  cout << endl;
  int i;
  if (p == NULL) {
    cout << "root is null" << endl;
  } else {
    cout << "root is not null" << endl;
  }
  for (i = 0; i < p->n; i++) {
    if (p == NULL) {
      cout << "current node is null" << endl;
    }
    if (p->l == false) {
      traverse(p->child_ptr[i]);
    }
    cout << " " << p->d[i];
  }
  if (p->l == false) {
    traverse(p->child_ptr[i]);
  }
  cout << endl;
}

// sort the tree
void sort(int *p, int n) {
  int i, j, t;
  for (i = 0; i < n; i++) {
    for (j = i; j <= n; j++) {
      if (p[i] > p[j]) {
        t = p[i];
        p[i] = p[j];
        p[j] = t;
      }
    }
  }
}

int split_child(BplusTree_t *x, int i) {
  int j, mid;
  BplusTree_t *np1, *np3, *y;
  np3 = init();
  np3->l = true;
  if (i == -1) {
    mid = x->d[2];
    x->d[2] = 0;
    x->n--;
    np1 = init();
    np1->l = false;
    x->l = true;
    for (j = 3; j < 6; j++) {
      np3->d[j - 3] = x->d[j];
      np3->child_ptr[j - 3] = x->child_ptr[j];
      np3->n++;
      x->d[j] = 0;
      x->n--;
    }
    for (j = 0; j < 6; j++) {
      x->child_ptr[j] = NULL;
    }
    np1->d[0] = mid;
    np1->child_ptr[np1->n] = x;
    np1->child_ptr[np1->n + 1] = np3;
    np1->n++;
    r = np1;
  } else {
    y = x->child_ptr[i];
    mid = y->d[2];
    y->d[2] = 0;
    y->n--;
    for (j = 3; j < 6; j++) {
      np3->d[j - 3] = y->d[j];
      np3->n++;
      y->d[j] = 0;
      y->n--;
    }
    x->child_ptr[i + 1] = y;
    x->child_ptr[i + 1] = np3; // something werid here.
  }
  return mid;
}

void insert(int a) {
  int i, t;
  x = r;
  if (x == NULL) {
    r = init();
    x = r;
  } else {
    if (x->l == true && x->n == 6) {
      t = split_child(x, -1);
      x = r;
      for (i = 0; i < (x->n); i++) {
        if ((a > x->d[i]) && (a < x->d[i + 1])) {
          i++;
          break;
        } else if (a < x->d[0]) {
          break;
        } else {
          continue;
        }
      }
      x = x->child_ptr[i];
    } else {
      while (x->l == false) {
        for (i = 0; i < (x->n); i++) {
          if ((a > x->d[i]) && (a < x->d[i + 1])) {
            i++;
            break;
          } else if (a < x->d[0]) {
            break;
          } else {
            continue;
          }
        }
        if ((x->child_ptr[i])->n == 6) {
          t = split_child(x, i);
          x->d[x->n] = t;
          x->n++;
          continue;
        } else {
          x = x->child_ptr[i];
        }
      }
    }
  }
  x->d[x->n] = a;
  sort(x->d, x->n);
  x->n++;
}
