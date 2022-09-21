 # GCC ONLY
 This macro library provides C with python dictionary. Specificly functions Executions.
python dictionary
```Python
map_condition = {
    "a": do_a,
    "b", do_b
}

result = map_condition.get(sample_str, do_this())()
```
C dictionary using this Library
```C
	new_dictionary(dic)
	dict_add(dic,"C",{
		printf("C is better yes!\n");
		int x=123;
		return x;
	})
	dict_add(dic,"Python",{
		printf("Python is trash lmao\a!\n");
		printf("Get life dude\n");
		main();
	})
	char temp[40];
	printf("What is your favorite programming language?\n");
	scanf("%s",temp);
	int x= dict_get(dic,temp)
	printf("%d\n",x);
```
Basic syntax

Creates new dictionary with the name dic
```C
new_dictionary(dic)
```
creates entry for string C with variadic arguments
```C
dict_add(NAME_OF_DICTIONARY,byte_array_used_as_key,{
		body of the function/lamda
	},list of arguments declaration)
```
gets result from the dictionary
```C
int x= dict_get(NAME_OF_DICTIONARY,byte_array_used_as_key,function arguments)
```
