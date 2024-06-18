//insertion
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0] = -1;
        size = 0;
    }
    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;
        //now correct position
        while(index>1){
            int parent = index/2;
            if(arr[index]>arr[parent]){
                swap(arr[index],arr[parent]);
                index = parent;
            }
            else{
                break;
            }
        }
    }

    //deletion
    void deletion(){
        arr[1]=arr[size];
        size -= 1;
        int index = 1;
        while(index<=size){
            int left = 2*index;
            int right = 2*index+1;
            int largest = index;
            if(left<=size && arr[index]<arr[left]){
                largest = left;
            }
            if(right<=size && arr[largest]<arr[right]){
                largest = right;
            }
            if(largest!=index){
                swap(arr[largest],arr[index]);
                index = largest;
            }
            else{
                break;
            }

        }
    }

    //heapify
    void heapify(int arr[],int n,int i ){
        int index = i;
        int left = 2*i;
        int right = 2*i+1;
        if(left<=n && arr[index]<arr[left]){
            index = left;
        }
        if(right<=n && arr[index]<arr[right]){
            index = right;
        }
        if(index!=i){
            swap(arr[index],arr[i]);
            heapify(arr,n,index);
        }
    }

    //build heap
    void buildheap(int arr[],int n){
        for(int i=n/2;i>0;i--){
            heapify(arr,n,i);
        }
    }

    //heap sort
    void heapsort(int arr[],int n){
        buildheap(arr,n);
        for(int i=n;i>1;i--){
            swap(arr[i],arr[1]);
            heapify(arr,i-1,1);
        }
    }
};