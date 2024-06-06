bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL && r2 ==NULL){
            return true;
        }
        else if (r1 == NULL && r2 != NULL){
            return false;
        }
        else if (r1 != NULL && r2 == NULL){
            return false;
        }
        bool l = isIdentical(r1->left,r2->left);
        bool r = isIdentical(r1->right,r2->right);
        bool c = r1->data == r2->data;
        if(l && r && c){
            return true;
        }
        else return false;
        //Your Code here
    }