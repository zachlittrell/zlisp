#include "list_functions.h"
#include <vector>
#include <cstdlib>
#include <utility>
#include <numeric>
namespace eval {
	const Function* list() {
		const static Function* v = new Function({ LispType::VARARG }, [](std::vector<LispVal>& vec) {
		/*	return std::accumulate(vec.rbegin(), vec.rend(), LispVal::NIL,
				[](auto& val, auto& old) {
					return LispVal(new std::pair<LispVal, LispVal>(val, old));
				});
			});*/
			if (vec.empty()) return LispVal::NIL;
			int i = vec.size() - 1;
			auto* pair = new std::pair<LispVal, LispVal>(vec[i], LispVal::NIL);
			for (--i; i != -1; i--) {
				pair = new std::pair<LispVal, LispVal>(vec[i], pair);
			}
			return LispVal(pair);
			});
		return v;
	}
	const  Function* _pair() {
		const static Function* v = new Function({ LispType::ANY,LispType::ANY }, [](std::vector<LispVal>& vec) {
			return new std::pair<LispVal, LispVal>(vec[0], vec[1]); });
		return v;
	}
	const  Function* fst() {
		const static Function* v = new Function({ LispType::PAIR }, [](auto& vec) {
			return std::get<0>(*vec[0].getpair()); });
		return v;
	}
	const  Function* snd() {
		const static Function* v = new Function({ LispType::PAIR }, [](auto& vec) {
			return std::get<1>(*vec[0].getpair()); });
		return v;
	}

	const  LispVal cons() {
		const static LispVal v = eval(
			"pair");
		return v;
	}

	const  LispVal head() {
		const static LispVal v = eval(
			"fst");
		return v;
	}


	const  LispVal tail() {
		const static LispVal v = eval(
			"snd");
		return v;
	}


	const  LispVal get() {
		const static LispVal v = eval(
			"(fn (^pair _list ^num _i) (if (= 0 _i) (head _list) (get (tail _list) (add _i -1))))");
		return v;
	}


	const  LispVal map() {
		const static LispVal v = eval(
			"(fn (^func _f ^pair _l)  (if (nil? _l) nil (cons (_f (head _l)) (map _f (tail _l)))))");
	
		return v;
	}

	const LispVal reduce() {
		const static LispVal v = eval(
			"(fn (^func _f _init _l) (if (nil? _l) _init (reduce _f (_f _init (head _l)) (tail _l))))"
		);
		return v;
	}

	const LispVal iterate() {
		const static LispVal v = eval(
			"(fn (^func _f _init ^num n) (if (= 0 n) (list _init) (cons _init (iterate _f (_f _init) (add n -1)))))"
		);
		return v;
	}

	const LispVal concat() {
		const static LispVal v = eval(
			"(fn (^pair l1 ^pair l2) (if (nil? l1) l2 (cons (head l1) (concat (tail l1) l2))))"
		);
		return v;
	}
	const LispVal filter() {
		const static LispVal v = eval(
			"(fn (^func f ^pair l) (if (nil? l) nil (if (f (head l)) (cons (head l) (filter f (tail l))) (filter f (tail l)))))"
		);
		return v;
	}

	const LispVal length() {
		const static LispVal v = eval(
			"(fn (^pair l) (if (nil? l) 0 (add 1 (length (tail l)))))"
		);
		return v;
	}




}