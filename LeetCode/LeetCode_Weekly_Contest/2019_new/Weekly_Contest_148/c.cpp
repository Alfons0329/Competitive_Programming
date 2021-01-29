class SnapshotArray 
{
    public:
        vector<map<int, int> > arr; // arr[i] is hash <snap_id, value>
        vector<int> primal;
        int snap_cnt = 0;
        SnapshotArray(int length) 
        {
            arr.resize(length);

        }

        void set(int index, int val) 
        {
            arr[index][snap_cnt] = val;

        }

        int snap() 
        {
            return snap_cnt++;

        }

        int get(int index, int snap_id) 
        {
            auto it = arr[index][snap_id];
            if(arr[index][snap_id] != 0)
            {
                return arr[index][snap_id];

            }
            else
            {
                while(snap_id--)
                {
                    if(arr[index][snap_id] != 0)
                    {
                        return arr[index][snap_id];

                    }

                }

            }
            return NULL;

        }

};

/**
 *  * Your SnapshotArray object will be instantiated and called as such:
 *   * SnapshotArray* obj = new SnapshotArray(length);
 *    * obj->set(index,val);
 *     * int param_2 = obj->snap();
 *      * int param_3 = obj->get(index,snap_id);
 *       *
