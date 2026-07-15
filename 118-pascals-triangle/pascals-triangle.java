class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new ArrayList<>();
        for(int row = 0; row<numRows;row++){
            List<Integer> ll= new ArrayList<>();
            int val = 1;
            for(int star = 0; star<= row; star++){
                ll.add(val);
                val = val*(row-star)/(star+1);
            }
            list.add(ll);
        }
        return list;
    }
}