// Author Ruslan Khamroev ruslankhamroev@gmail.com 
//09.21.2022
//No rights reserver no waranty
#ifndef MAX_SIZE
#define MAX_SIZE 10000
#endif
#define CAT(a,b) CAT_(a,b)
#define CAT_(a,b) a##b

#define new_dictionary(NAME) int (*NAME[MAX_SIZE]) (int,...);

//it has to be one liner coz it depends on __LINE__ macro 

#define dict_add(NAME,KEY,BODY, ...)int CAT(anon_______,__LINE__)( __VA_ARGS__ ){BODY};int (*CAT(anon_ptr,__LINE__))( __VA_ARGS__ ) = &(CAT(anon_______,__LINE__)); NAME[hash(KEY)%MAX_SIZE]=CAT(anon_ptr,__LINE__); \

#define dict_get(NAME,KEY,...) (NAME[hash(KEY)%MAX_SIZE])(1,##__VA_ARGS__);
unsigned long
hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
void dummy(int a,...){
    //do nothing
}
