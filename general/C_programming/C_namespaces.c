/*
* Demo of C identifier namespaces
* C namespaces:
* 1) Label names (the goto type).
* 2) Tags (names of structures, unions and enumerations).
* 3) Members of structures and unions (these have a separate namespace per structure/union).
* 4) All other identifiers (function names, object names, type(def) names,
* enumeration constants, etc).
*/

int mystruct; 	// DOES NOT collide with 'struct mystruct'
int same_member_name; // DOES NOT collide with struct mystruct's member

int do_nothing()
{
	return 0;
}

struct mystruct {
	int same_member_name; 	// DOES NOT collide with mysecondstruct's member
};

struct mysecondstruct {
	int same_member_name;
};

struct mythirdstruct {
	int mythirdstruct; 	//DOES NOT collide with struct mythirdstruct
	int exit;		//DOES NOT collide with label 'exit'
	int do_nothing;		//DOES NOT collide with struct or function do_nothing
};

struct do_nothing { 		//DOES NOT collide with function do_nothing
	int same_member_name;
};

int main()
{
	int exit; 		//DOES NOT collide with label 'exit'
	int a = 1;

	switch (a) {
	case 1:
		goto do_nothing; //DOES NOT collide with function do_nothing
	case 2:
		goto exit; 	//DOES NOT collide with 'int exit'

	}
	goto mysecondstruct;	//DOES NOT collide with struct mysecondstruct

do_nothing:
	return 0;

exit:
	return 0;

mysecondstruct:
	return 0;
}
