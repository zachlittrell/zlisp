#pragma once
#include "function.h"
#include "..//zlisp_evaluator.h"
/**
* Functions for creating and manipulating lists
*/
namespace eval {

	const  Function* list();
	const  Function* _pair();
	const  Function* fst();
	const  Function* snd();

	const  LispVal cons();
	const  LispVal head();
	const  LispVal tail();

	const  LispVal get();
	const  LispVal map();

	


}