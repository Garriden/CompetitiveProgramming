    ListNode* reverseListBF(ListNode* head) {   
        if(head == nullptr or head->next == nullptr) return head;

        ListNode* node1 = head;
        ListNode* node2 = nullptr;
        vector<int> values;

        while(node1 != nullptr) {
            values.push_back(node1->val);
            node1 = node1->next;
        }

        for (int ii = 0; ii < values.size(); ++ii) {
            ListNode* newNode = new ListNode(values[ii]);
            newNode->next = node2;
            node2 = newNode;
        }

        return node2;
    }
    
    
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* previous = nullptr;
        ListNode* current = head;
        ListNode* forward = nullptr;

        while(current != nullptr) {
            forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;
        }

        return previous;
    }
    
    
    

	ListNode* recurs(ListNode* curr, ListNode* prev) {
        if(curr == nullptr) {
            return prev;
        } else {
            ListNode* froward = curr->next;
            curr->next = prev;
            return recurs(froward,curr);
        }

    }

    ListNode* reverseListRecursive(ListNode* head) {
        return recurs(head, nullptr);
    }
