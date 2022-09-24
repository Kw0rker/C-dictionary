// Author Ruslan Khamroev ruslankhamroev@gmail.com 
//09.21.2022
//No rights reserver no waranty


#ifndef MAX_SIZE
#define MAX_SIZE 10000
#endif
#define CAT(a,b) CAT_(a,b)
#define CAT_(a,b) a##b

#define GET_ARGS_COUNT(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,x,...) x
#define FOO(...) GET_ARGS_COUNT(__VA_ARGS__,\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t,size_t),\
(int,size_t,size_t,size_t),\
(int,size_t,size_t),\
(int,size_t))\




#define new_dictionary(NAME) int (*NAME[MAX_SIZE]) (int,...);

//it has to be one liner coz it depends on __LINE__ macro 

#define dict_add(NAME,KEY,BODY, ...)int CAT(anon_______,__LINE__)(int __never_acces__,##__VA_ARGS__ ){BODY};NAME[hash(KEY)%MAX_SIZE]=&(CAT(anon_______,__LINE__));\


#define dict_get(NAME,KEY,...) ((int(*)FOO(__VA_ARGS__))NAME[hash(KEY)%MAX_SIZE])(1,##__VA_ARGS__)


unsigned long
hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

