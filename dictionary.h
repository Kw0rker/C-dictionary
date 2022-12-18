// Author Ruslan Khamroev ruslankhamroev@gmail.com 
//09.21.2022
//No rights reserver no waranty

#include <stddef.h>
#ifndef MAX_SIZE
#define MAX_SIZE 10000
#endif
#define CAT(a,b) CAT_(a,b)
#define CAT_(a,b) a##b

#define _ARG_25(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,x,...) x
#define FOO(...) _ARG_25(ISEMPTY2(__VA_ARGS__),__VA_ARGS__,\
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
(int,size_t),\
(int))

#define HAS_COMMA(...) _ARG_25(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 0)

#define _TRIGGER_PARENTHESIS_(...) ,

#define ISEMPTY(...)                                                    \
_ISEMPTY(                                                               \
          /* test if there is just one argument, eventually an empty    \
             one */                                                     \
          HAS_COMMA(__VA_ARGS__),                                       \
          /* test if _TRIGGER_PARENTHESIS_ together with the argument   \
             adds a comma */                                            \
          HAS_COMMA(_TRIGGER_PARENTHESIS_ __VA_ARGS__),                 \
          /* test if the argument together with a parenthesis           \
             adds a comma */                                            \
          HAS_COMMA(__VA_ARGS__ (/*empty*/)),                           \
          /* test if placing it between _TRIGGER_PARENTHESIS_ and the   \
             parenthesis adds a comma */                                \
          HAS_COMMA(_TRIGGER_PARENTHESIS_ __VA_ARGS__ (/*empty*/))      \
          )
#define PASTE5(_0, _1, _2, _3, _4) _0 ## _1 ## _2 ## _3 ## _4
#define _ISEMPTY(_0, _1, _2, _3) HAS_COMMA(PASTE5(_IS_EMPTY_CASE_, _0, _1, _2, _3))
#define _IS_EMPTY_CASE_0001 ,


#define ISEMPTY2(...)                                                    \
_ISEMPTY2(                                                               \
          /* test if there is just one argument, eventually an empty    \
             one */                                                     \
          HAS_COMMA(__VA_ARGS__),                                       \
          /* test if _TRIGGER_PARENTHESIS_ together with the argument   \
             adds a comma */                                            \
          HAS_COMMA(_TRIGGER_PARENTHESIS_ __VA_ARGS__),                 \
          /* test if the argument together with a parenthesis           \
             adds a comma */                                            \
          HAS_COMMA(__VA_ARGS__ (/*empty*/)),                           \
          /* test if placing it between _TRIGGER_PARENTHESIS_ and the   \
             parenthesis adds a comma */                                \
          HAS_COMMA(_TRIGGER_PARENTHESIS_ __VA_ARGS__ (/*empty*/))      \
          )
#define _ISEMPTY2(_0, _1, _2, _3) PASTE5(_IS_EMPTY_CASE_, _0, _1, _2, _3)

#define new_dictionary_bool(NAME) _Bool NAME[MAX_SIZE]
#define new_dictionary_char(NAME) char NAME[MAX_SIZE]
#define new_dictionary_short_int(NAME) short int NAME[MAX_SIZE]
#define new_dictionary_int(NAME) int NAME[MAX_SIZE]
#define new_dictionary_long_int(NAME) long int NAME[MAX_SIZE]
#define new_dictionary_long_long_int(NAME) long long int NAME[MAX_SIZE]
#define new_dictionary_float(NAME) float NAME[MAX_SIZE]
#define new_dictionary_long_double(NAME) long double NAME[MAX_SIZE]
#define new_dictionary_void_ptr(NAME) void * NAME[MAX_SIZE]

#define new_dictionary_unsigned_char(NAME) unsigned char NAME[MAX_SIZE]
#define new_dictionary_singed_char(NAME) signed char NAME[MAX_SIZE]
#define new_dictionary_unsigned_short_int(NAME) unsigned short int NAME[MAX_SIZE]
#define new_dictionary_unsigned_int(NAME) unsigned int NAME[MAX_SIZE]
#define new_dictionary_unsigned_long_int(NAME) void * NAME[MAX_SIZE]
#define new_dictionary_unsigned_long_long_int(NAME) unsigned long long int NAME[MAX_SIZE]
#define new_dictionary_double(NAME) double NAME[MAX_SIZE]
#define new_dictionary_char_ptr(NAME) char * NAME[MAX_SIZE]
#define new_dictionary_int_ptr(NAME) int * NAME[MAX_SIZE]
#define new_dictionary_function(NAME) int (*NAME[MAX_SIZE]) (int,...)

#define new_dictionary(NAME,...) CAT(dictonary_case_,ISEMPTY(__VA_ARGS__))(NAME,__VA_ARGS__);
//if type is defined
#define dictonary_case_0(NAME,ARGS) typeof(ARGS) (NAME)[MAX_SIZE] 
//if user didnt pass type create function 
#define dictonary_case_1(NAME,ARGS) int (*NAME[MAX_SIZE]) (int,...)
enum t_typename {
        TYPENAME_BOOL,
        TYPENAME_CHAR,
        TYPENAME_SHORT_INT,
        TYPENAME_INT,
        TYPENAME_LONG_INT,
        TYPENAME_LONG_LONG_INT,
        TYPENAME_FLOAT,
        TYPENAME_LONG_DOULBE,
        TYPENAME_VOID_PTR,
        TYPENAME_UNSIGNED_CHAR,
        TYPENAME_SIGNED_CHAR,
        TYPENAME_UNSIGNED_SHORT_INT,
        TYPENAME_UNSIGNED_INT,
        TYPENAME_UNSIGNED_LONG_INT,
        TYPENAME_UNSIGNED_LONG_LONG_INT,
        TYPENAME_DOUBLE,
        TYPENAME_CHAR_PTR,
        TYPENAME_INT_PTR,
        TYPENAME_OTHER
};
#define type_of(x) _Generic((x),                                                                \
_Bool: TYPENAME_BOOL,                  unsigned char: TYPENAME_UNSIGNED_CHAR,                   \
char: TYPENAME_CHAR,                   signed char: TYPENAME_SIGNED_CHAR,                       \
short int: TYPENAME_SHORT_INT,         unsigned short int: TYPENAME_UNSIGNED_SHORT_INT,         \
int: TYPENAME_INT,                     unsigned int: TYPENAME_UNSIGNED_INT,                     \
long int: TYPENAME_LONG_INT,           unsigned long int: TYPENAME_UNSIGNED_LONG_INT,           \
long long int: TYPENAME_LONG_LONG_INT, unsigned long long int: TYPENAME_UNSIGNED_LONG_LONG_INT, \
float: TYPENAME_FLOAT,                 double: TYPENAME_DOUBLE,                                 \
long double: TYPENAME_LONG_DOULBE,     char *: TYPENAME_CHAR_PTR,                               \
void *: TYPENAME_VOID_PTR,             int *: TYPENAME_INT_PTR,                                 \
default:TYPENAME_OTHER)\

static _Bool BOOL;static char CHAR; static short int SHORT_INT;static int INT;
static long int LONG_INT;static long long int LONG_LONG_INT;static float FLOAT;
static long double LONG_DOUBLE;static void * VOID;static unsigned char UNSIGNED_CHAR;
static signed char SIGNED_CHAR;static  unsigned short int UNSIGNED_SHORT_INT;
static unsigned int UNSIGNED_INT;static unsigned long int UNSIGNED_LONG_INT;
static unsigned long long int UNSIGNED_LONG_LONG_INT;
static double DOUBLE; static char  * CHAR_PTR; static int * INT_PTR; 

void change(size_t a,_Bool val);
void change2(size_t a,char val);
void change3(size_t a,short int val);
void change4(size_t a,int val);
void change5(size_t a,long int val);
void change6(size_t a,long long int val);
void change7(size_t a,float val);
void change8(size_t a,long double val);
void change9(size_t a,void* val);
void change10(size_t a,unsigned char val);
void change11(size_t a,signed char val);
void change12(size_t a,unsigned short int val);
void change13(size_t a,unsigned int val);
void change14(size_t a,unsigned long int val);
void change15(size_t a,unsigned long long int val);
void change16(size_t a,double val);
void change17(size_t a,char* val);
void change18(size_t a,int* val);

void change(size_t a,_Bool val){
   *(_Bool*)a=val;
}
void change2(size_t a,char val){
   *(char*)a=val;
}
void change3(size_t a,short int val){
   *(short int*)a=val;
}
void change4(size_t a,int val){
   *(int*)a=val;
}
void change5(size_t a,long int val){
   *(long int*)a=val;
}
void change6(size_t a,long long int val){
   *(long long int*)a=val;
}
void change7(size_t a,float val){
   *(float*)a=val;
}
void change8(size_t a,long double val){
   *(long double*)a=val;
}
void change9(size_t a,void* val){
   *(size_t*)a=val;
}
void change10(size_t a,unsigned char val){
   *(unsigned char*)a=val;
}
void change11(size_t a,signed char val){
   *(signed char*)a=val;
}
void change12(size_t a,unsigned short int val){
   *(unsigned short int*)a=val;
}
void change13(size_t a,unsigned int val){
   *(unsigned int*)a=val;
}
void change14(size_t a,unsigned long int val){
   *(unsigned long int*)a=val;
}
void change15(size_t a,unsigned long long int val){
   *(unsigned long long int*)a=val;
}
void change16(size_t a,double val){
   *(double *)a=val;
}
void change17(size_t a,char* val){
   *(char *)a=val;
}
void change18(size_t a,int* val){
   *(int *)a=val;
}

#define CHANGE(x) _Generic((x),                                                                \
_Bool: change((size_t)&BOOL,(_Bool)x),                  unsigned char: change10((size_t)&UNSIGNED_CHAR,(unsigned char)x),                   \
char: change2((size_t)&CHAR,(char)x),                   signed char: change11((size_t)&SIGNED_CHAR,(signed char)x),                       \
short int: change3((size_t)&SHORT_INT,(short int)x),         unsigned short int: change12((size_t)&UNSIGNED_SHORT_INT,(unsigned short int)x),         \
int: change4((size_t)&INT,(int)x),                     unsigned int: change13((size_t)&UNSIGNED_INT,(unsigned int)x),                     \
long int: change5((size_t)&LONG_INT,(long int)x),           unsigned long int: change14((size_t)&UNSIGNED_LONG_INT,(unsigned long int)x),           \
long long int: change6((size_t)&LONG_LONG_INT,(long long int)x), unsigned long long int: change15((size_t)&UNSIGNED_LONG_LONG_INT,(unsigned long long int)x), \
float: change7((size_t)&FLOAT,(float)x),                 double: change16((size_t)&DOUBLE,(double)x),                                 \
long double: change8((size_t)&LONG_DOUBLE,(long double)x),     char *: change17((size_t)&CHAR_PTR,(char *)x),                               \
void *: change9((size_t)&VOID,(void *)x),                  int *:change18((size_t)&INT_PTR,(int *)x),                                 \



//it has to be one liner coz it depends on __LINE__ macro 
#define dict_add(NAME,KEY,BODY, ...) _Generic(((NAME)[0]),\
_Bool: (change((size_t)&BOOL,(_Bool)BODY),NAME[hash(KEY)%MAX_SIZE]=({BOOL})),                                   unsigned char:(change10((size_t)&UNSIGNED_CHAR,(unsigned char)BODY),NAME[hash(KEY)%MAX_SIZE]=UNSIGNED_CHAR),         \
char: (change2((size_t)&CHAR,(char)BODY),NAME[hash(KEY)%MAX_SIZE]=CHAR),                                     signed char: (change11((size_t)&SIGNED_CHAR,(signed char)BODY),NAME[hash(KEY)%MAX_SIZE]=SIGNED_CHAR),            \
short int: (change3((size_t)&SHORT_INT,(short int)BODY),NAME[hash(KEY)%MAX_SIZE]=SHORT_INT),                     unsigned short int:(change12((size_t)&UNSIGNED_SHORT_INT,(unsigned short int)BODY),NAME[hash(KEY)%MAX_SIZE]=UNSIGNED_SHORT_INT),     \
int: (change4((size_t)&INT,(int)BODY),NAME[hash(KEY)%MAX_SIZE]=INT),                                        unsigned int: (change13((size_t)&UNSIGNED_INT,(unsigned int)BODY),NAME[hash(KEY)%MAX_SIZE]=UNSIGNED_INT),           \
long int: (change5((size_t)&LONG_INT,(long int)BODY),NAME[hash(KEY)%MAX_SIZE]=LONG_INT),                        unsigned long int: (change14((size_t)&UNSIGNED_LONG_INT,(unsigned long int)BODY),NAME[hash(KEY)%MAX_SIZE]=UNSIGNED_LONG_INT),      \
long long int: (change6((size_t)&LONG_LONG_INT,(long long int)BODY),NAME[hash(KEY)%MAX_SIZE]=LONG_LONG_INT),         unsigned long long int: (change15((size_t)&UNSIGNED_LONG_LONG_INT,(unsigned long long int)BODY), NAME[hash(KEY)%MAX_SIZE]=UNSIGNED_LONG_LONG_INT), \
float: (change7((size_t)&FLOAT,(float)BODY),NAME[hash(KEY)%MAX_SIZE]=FLOAT),                               double: (change16((size_t)&DOUBLE,(double)BODY), NAME[hash(KEY)%MAX_SIZE]=DOUBLE),                 \
long double:(change8((size_t)&LONG_DOUBLE,(long double)BODY), NAME[hash(KEY)%MAX_SIZE]=LONG_DOUBLE),               char *: (change17((size_t)&CHAR_PTR,(char *)BODY), NAME[hash(KEY)%MAX_SIZE]=CHAR_PTR),                 \
void *: (change9((size_t)&VOID,(void *)BODY), NAME[hash(KEY)%MAX_SIZE]=VOID),                                  int *: (change18((size_t)&INT_PTR,(int *)BODY),NAME[hash(KEY)%MAX_SIZE]=INT_PTR),                   \
default: ({ int CAT(anon_______,__LINE__)(int __never_acces__,##__VA_ARGS__ ) {BODY;} NAME[hash(KEY)%MAX_SIZE]=_Generic((NAME[0]),_Bool: 0,unsigned char: 0, char: 0,signed char: 0,short int: 0,unsigned short int: 0,int: 0,unsigned int: 0,long int: 0,unsigned long int: 0,long long int: 0, unsigned long long int: 0,float: 0,double: 0,long double: 0,char *: &(char){0},void *: &(void*){0},int *: &(int){0}, default:&(CAT(anon_______,__LINE__)));}))

#define dict_get(NAME,KEY,...) _Generic(((NAME)[0]),                                               \
_Bool: NAME[hash(KEY)%MAX_SIZE],         unsigned char: NAME[hash(KEY)%MAX_SIZE],          \
char: NAME[hash(KEY)%MAX_SIZE],          signed char: NAME[hash(KEY)%MAX_SIZE],            \
short int: NAME[hash(KEY)%MAX_SIZE],     unsigned short int: NAME[hash(KEY)%MAX_SIZE],     \
int: NAME[hash(KEY)%MAX_SIZE],           unsigned int: NAME[hash(KEY)%MAX_SIZE],           \
long int: NAME[hash(KEY)%MAX_SIZE],      unsigned long int: NAME[hash(KEY)%MAX_SIZE],      \
long long int: NAME[hash(KEY)%MAX_SIZE], unsigned long long int: NAME[hash(KEY)%MAX_SIZE], \
float: NAME[hash(KEY)%MAX_SIZE],         double: NAME[hash(KEY)%MAX_SIZE],                 \
long double: NAME[hash(KEY)%MAX_SIZE],   char *: NAME[hash(KEY)%MAX_SIZE],                 \
void *: NAME[hash(KEY)%MAX_SIZE],        int *: NAME[hash(KEY)%MAX_SIZE],                   \
default: ((int(*)FOO(__VA_ARGS__))NAME[hash(KEY)%MAX_SIZE])(1,##__VA_ARGS__))

unsigned long
hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
#define if_contexptr(expr,code) _Generic((1 ? ((void*)((expr)*0l)) : &(int){1}), (code), void*: 0)