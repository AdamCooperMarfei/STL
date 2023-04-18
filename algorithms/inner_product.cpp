template<class InputIterator1, class InputIterator2, class T>
T inner_product(InputIterator1 first1, InputIterator1 last1, 
                InputIterator2 first2, InputIterator2 last2, T init){
    for(; first1 != last1; ++first1, ++first2){
        init = init + (*first1 * *first2);
    }
    return init;
}
template<class InputIterator1, class InputIterator2, class T,
class BinaryOperation1, class BinaryOperation2>
T inner_product(InputIterator1 first1, InputIterator1 last1, 
                InputIterator2 first2, InputIterator2 last2, T init, 
                BinaryOperation1 binary_op1,
BinaryOperation2 binary_op2){
    for(; first1 != last1; ++first1, ++first2){
        init = binary_op1(init, binary_op2(*first1, first2));
    }
    return init;
}
