### [Sort Binary Linked List](https://www.interviewbit.com/problems/sort-binary-linked-list/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* a) {
    if(!a) return a;
    ListNode dummy1(0);
    ListNode* zero = &dummy1;
    ListNode dummy2(0);
    ListNode* one = &dummy2;

    while(a) {
        if (a->val == 0) {
            zero->next = a;
            zero = zero->next;
        }
        else {
            one->next = a;
            one = one->next;
        }
        a = a->next;
    }

    one->next = NULL;
    if(!dummy1.next) return dummy2.next;
    zero->next = dummy2.next;
    return dummy1.next;
}
```

### [Partition List](https://www.interviewbit.com/problems/partition-list/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* a, int b) {
    if(!a || !a->next) return a;
    ListNode dummy1(0);
    ListNode dummy2(0);
    ListNode* lx = &dummy1;
    ListNode* gx = &dummy2;
    while(a) {
        if (a->val<b) {
            lx->next = a;
            lx = lx->next;
        }
        else {
            gx->next = a;
            gx = gx->next;
        }
        a = a->next;
    }
    gx->next = NULL;
    if(!dummy1.next) return dummy2.next;
    lx->next = dummy2.next;
    return dummy1.next;
}
```

### [Insertion Sort List](https://www.interviewbit.com/problems/insertion-sort-list/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* a) {
    if(!a->next) return a;
    ListNode dummy(-1);
    dummy.next = a;
    ListNode* iter = a->next;
    while(iter) {
        ListNode* temp = dummy.next;
        ListNode* pre = &dummy;
        ListNode* save = iter->next;
        while(temp!=iter) {
            if(temp->val>iter->val) {
                pre->next = iter;
                iter->next = temp;
                break;
            }
            pre = temp;
            temp = temp->next;
        }
        while(temp && temp->next!=iter) {
            temp = temp->next;
        }
        if(temp) temp->next = save;
        iter = save;
    }
    return dummy.next;
}
```

### [Amazing Subarrays](https://www.interviewbit.com/problems/amazing-subarrays/)

```cpp
int Solution::solve(string s) {
    int n = s.size(),ans=0;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    // cout<<s<<"\n";
    for(int i=0;i<n;i++) {
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
            ans+=(n-i);
            ans%=10003;
        }
    }
    return ans;
}
```

### [Sort List](https://www.interviewbit.com/problems/sort-list/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* merge(ListNode* a, ListNode* b) {
    ListNode dummy(0);
    ListNode* iter = &dummy;

    while(a && b) {
        if(a->val<b->val) {
            iter->next = a;
            a = a->next;
        }
        else {
            iter->next = b;
            b = b->next;
        }
        iter = iter->next;
    }

    if(a) iter->next = a;
    else iter ->next = b;

    return dummy.next;
 }

ListNode* Solution::sortList(ListNode* a) {
    if(!a || !a->next) return a;
    ListNode* slow = a;
    ListNode* fast = a;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* iter = slow->next;
    slow->next = NULL;
    ListNode* l1 = sortList(a);
    ListNode* l2 = sortList(iter);

    return merge(l1, l2);
}
```

### [Palindrome List (Star Marked)](https://www.interviewbit.com/problems/palindrome-list/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* x) {
     if (x->next==NULL) return x;
     ListNode* small_head = reverse(x->next);
     ListNode* small_tail = x->next;
     small_tail->next = x;
     x->next = NULL;
     return small_head;
 }

int Solution::lPalin(ListNode* a) {
    ListNode* slow = a;
    ListNode* fast = a;
    if (a==NULL || (a->next==NULL)) return 1;
    if (a->next->next==NULL) {
        if (a->val==a->next->val) return 1;
        else return 0;
    }
    while (fast->next!=NULL && fast->next->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* new_head = reverse(slow->next);
    while (a!=NULL && new_head!=NULL) {
        if (new_head->val!=a->val) return 0;
        a=a->next;
        new_head=new_head->next;
    }
    return 1;
}
```

### [Remove Duplicates from Sorted List II (Star Marked)](https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* a) {
    ListNode* attach = NULL;
    ListNode* head = NULL;
    ListNode* iter = a;
    while (iter!=NULL) {
        int cnt = 0;
        ListNode* node = iter;
        int store = iter->val;
        while (iter!=NULL && iter->val==store) {
            cnt++;
            iter=iter->next;
        }
        if (cnt==1) {
            if (attach==NULL) {
                attach = node;
                head = node;
                attach->next = NULL;
            }
            else {
                attach->next = node;
                attach = attach->next;
                attach->next = NULL;
            }
        }
    }
    return head;
}
```

### [Merge Two Sorted Lists (Star Marked)](https://www.interviewbit.com/problems/merge-two-sorted-lists/)

```cpp
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* a, ListNode* b) {
    if (a==NULL) return b;
    if (b==NULL) return a;
    ListNode* head=NULL;
    if (a->val<b->val) {
        head = a;
        a = a->next;
    }
    else {
        head = b;
        b = b->next;
    }
    ListNode* attach = head;

    while (a && b) {
        if (a->val<b->val) {
            attach->next = a;
            a = a->next;
        }
        else {
            attach->next = b;
            b = b->next;
        }
        attach=attach->next;
    }

    if (a) attach->next = a;
    else attach->next = b;

    return head;
}
```

### [Remove Duplicates from Sorted List](https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* a) {
    ListNode* head = NULL;
    ListNode* attach = NULL;
    ListNode* iter = a;
    while (iter) {
        ListNode* node = iter;
        int store = iter->val;
        while(iter!=NULL && iter->val==store) {
            iter=iter->next;
        }
        if (head == NULL) {
            head = node;
            attach = node;
            attach->next = NULL;
        }
        else {
            attach->next = node;
            attach = attach->next;
            attach->next = NULL;
        }
    }
    return head;
}
```

### [Remove Nth Node from List End (Star Marked)](https://www.interviewbit.com/problems/remove-nth-node-from-list-end/s)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* a, int b) {
    ListNode* slow = a;
    ListNode* fast = a;
    // we will go to the (b + 1)th node from starting
    for(int i=0;i<b;i++)
    {
        fast = fast->next;
        if(fast == NULL)
        {
            return a->next;
        }
    }
    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return a;
}
```

### [K reverse linked list (Star Marked)](https://www.interviewbit.com/problems/k-reverse-linked-list/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reversell(ListNode* head, ListNode* tail) {
    if (head == tail) return head;
    ListNode* small_head = reversell(head->next, tail);
    ListNode* small_tail = head->next;
    small_tail->next = head;
    head->next = NULL;
    return small_head;
}


ListNode* Solution::reverseList(ListNode* a, int k) {
    ListNode* iter = a;
    ListNode* head = NULL;
    ListNode* attach = NULL;
    while(iter) {
        ListNode* new_tail = iter;
        int cnt = 1;
        while(cnt<k) {
            iter = iter->next;
            cnt++;
        }
        ListNode* tail_next = iter->next;
        ListNode* new_head = reversell(new_tail,iter);
        iter = tail_next;
        // cout<<new_head->val<<"\n";
        if (head) {
            attach->next = new_head;
            if (tail_next) new_tail->next = tail_next;
            attach = new_tail;
        }
        else {
            head = new_head;
            attach = new_tail;
        }
    }
    return head;
}
```

### [Swap List Nodes in pairs](https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::swapPairs(ListNode* a) {
    if (!a || !a->next) return a;
    ListNode* nxt = a->next->next;
    ListNode* sh = a->next;
    a->next->next = a;
    a->next = swapPairs(nxt);
    return sh;
}
```

### [Rotate List](https://www.interviewbit.com/problems/rotate-list/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* a, int b) {
    ListNode* slow = a;
    ListNode* fast = a;
    int n = 0;
    while (slow) {
        slow = slow->next;
        n++;
    }
    b = b%n;
    if (b == 0) return a;
    slow = a;
    for(int i = 0;i<b-1;i++) {
        fast = fast->next;
    }
    ListNode* pre = NULL;
    while(fast->next != NULL) {
        pre = slow;
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = a;
    pre->next = NULL;
    return slow;
}
```

### [Kth Node From Middle](https://www.interviewbit.com/problems/kth-node-from-middle/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* a, int b) {
    int n = 0;
    ListNode* iter = a;
    while(iter) {
        iter = iter->next;
        n++;
    }
    int mid = n/2;
    int pos = mid - b;
    if(pos<0) return -1;
    int cnt = 0;
    iter = a;
    while(iter) {
        if(pos == cnt) return iter->val;
        iter = iter->next;
        cnt++;
    }
}
```

### [Reverse Alternate K Nodes](https://www.interviewbit.com/problems/reverse-alternate-k-nodes/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* a, int b) {
    if(!a || !a->next) return a;
    ListNode* prev = NULL;
    ListNode* cur = a;
    ListNode* nxt;
    int cnt = 0;
    while(cur && cnt<b) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
        cnt++;
    }
    if(cur && cnt == b) {
        cnt = 0;
        while(cur && cnt<b) {
            a->next = cur;
            a = a->next;
            cur = cur->next;
            cnt++;
        }
        if(cur && cnt == b) {
            a->next = solve(cur, b);
        }
    }
    return prev;
}
```

### [Reverse Link List II](https://www.interviewbit.com/problems/reverse-link-list-ii/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reversell(ListNode* head, ListNode* tail) {
    if(head == tail) return head;
    ListNode* sh = reversell(head->next, tail);
    ListNode* st = head->next;
    st->next = head;
    st = st->next;
    st->next = NULL;
    return sh;
}

ListNode* Solution::reverseBetween(ListNode* a, int b, int c) {
    b--; c--;

    ListNode* sh = NULL;
    ListNode* st = NULL;
    ListNode* save_nt = NULL;
    ListNode* iter = a;
    int cnt = 0;
    while(iter) {
        if(cnt == b) sh = iter;
        if(cnt == c) {
            st = iter;
            save_nt = iter->next;
        }
        cnt++;
        iter = iter->next;
    }
    iter = a;
    ListNode dummy(0);
    dummy.next = a;
    ListNode* pre = &dummy;
    iter = a;
    while(iter) {
        if(iter == sh) {
            ListNode* new_head = reversell(sh,st);
            sh->next = save_nt;
            pre->next = new_head;
            return dummy.next;
        }
        pre = iter;
        iter = iter->next;
    }
}
```

### [Reorder List](https://www.interviewbit.com/problems/reorder-list/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reversell(ListNode* head) {
    if(head->next == NULL) return head;
    ListNode* sh = reversell(head->next);
    ListNode* st = head->next;
    st->next = head;
    st = st->next;
    st->next = NULL;
    return sh;
}

ListNode* Solution::reorderList(ListNode* a) {
    if(!a || !a->next) return a;
    ListNode* slow = a;
    ListNode* fast = a;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* new_head = reversell(slow->next);
    slow->next = NULL;
    int turn = 1;
    ListNode dummy(0);
    ListNode* head = &dummy;
    while(a || new_head) {
        if(turn) {
            head->next = a;
            a = a->next;
        }
        else {
            head->next = new_head;
            new_head = new_head->next;
        }
        head = head->next;
        turn = 1 - turn;
    }
    return dummy.next;
}
```

### [Add Two Numbers as Lists](https://www.interviewbit.com/problems/add-two-numbers-as-lists/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* a, ListNode* b) {
    ListNode dummy(0);
    ListNode* head = &dummy;
    int carry = 0;
    while(a || b || carry) {
        int value = ((a ? a->val : 0) + (b ? b->val : 0) + carry);
        if (a) a = a->next;
        if (b) b = b->next;
        ListNode* nw = new ListNode(value%10);
        carry = value/10;
        head->next = nw;
        head = head->next;
    }
    return dummy.next;
}
```

### [List Cycle](https://www.interviewbit.com/problems/list-cycle/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* slow = a;
    ListNode* fast = a;
    while(true) {
        if(!fast->next) return NULL;
        if(!fast->next->next) return NULL;
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    slow = a;
    while(slow!=fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
```
