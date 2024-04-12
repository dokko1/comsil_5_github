#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

template <typename T> //다형성을 위한 임의 타입 선언
//LinkedList class를 상속받음
class Stack : public LinkedList<T>{
	public:
		bool Delete (T &element){
			//first가존재하지않으면 false반환
			if(this->first == NULL) return false;
			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			element = this->first->data;
			Node<T> *cur_first = this->first;
                        this->first = this->first->link; //first를 삭제하기 위해 첫 번째 element를 밀어냄
                        delete cur_first; //첫 element 삭제
                        this->current_size--;
			return true;
		}
};
