/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *index = head;
        ListNode *position = head->next;

        int value = head->val;

        while (position != NULL) {
            if (position->val == value) {
                index->next = position->next;
                delete position;
                position = index->next;
            } else {
                value = position->val;
                index = position;
                position = position->next;
            }
        }
    return head;
    }
};

int main() {
    ListNode *A = new ListNode(1);
    ListNode *B = new ListNode(1);
    B->next = A;
    ListNode *C = new ListNode(1);
    C->next = B;
    ListNode *D = new ListNode(2);
    D->next = C;
    Solution test;
    ListNode *result = test.deleteDuplicates(D);
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

}
