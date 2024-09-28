// find if the list is circular or not
// return in bool
/*
		Time Complexity: O(N)
		Space Complexity: O(1),
		
		where N is the length of the given Linked List.
*/


/*bool isCircular(Node * head) {
    // If head is already NULL, then it is the circular linked list
    // with length zero.
    if (head == NULL) {
        return true;
    }

    // If next pointer of head is already NULL, then it the linear linked
    // list of length 1, hence we return false here.
    if (head -> next == NULL) {
        return false;
    }

    // Initialising slow and fast pointers with head.
    Node * slow = head, * fast = head;

    // Iterating through the linkedlist till, fast doesn't reach end of 
    // linked list or slow pointer will not become equal to fast pointer.
    while (fast != NULL && fast -> next != NULL) {

        // Moving slow pointer by one step.
        slow = slow -> next;
        // Moving fast pointer by two steps.
        fast = fast -> next -> next;

        // Checking if updated slow and fast pointer values are same or not.
        if (slow == fast) {
            break;
        }

    }

    // After completing the traversal, if slow and fast pointers meet and 
    // the node of meeting is node pointed by head, then linkedlist is circular.
    if (slow == fast && slow == head) {
        return true;
    }

    // If linkedlist is not circular, then return false.
    return false;
} */
