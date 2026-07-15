class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> list = new ArrayList<>();
        long val = 1;
        for(int star = 0; star<=rowIndex;star++){
            list.add((int) val);
            val = val*(rowIndex - star)/(star+1);
        }
        return list;
    }
}