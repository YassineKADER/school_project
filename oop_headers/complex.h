#include <iostream>
#define print(x) std::cout<< x <<std::endl
#define get(x) std::cin>> x 
class complex{
    int rel, img;
    public:
    void set_complex(int rel, int img);
    void get_complex();
    complex(){rel=0 ;img=0;}
    complex operator+ (const complex &obj);
    complex operator- (const complex &obj);
    complex operator* (const complex &obj);
    bool operator== (const complex &obj);
    void operator= (const complex &obg);

};
void complex::get_complex(){
    if (img >= 0)print(rel<<"+i"<<img);
    if (img < 0)print(rel<<"-i"<<(img)*(-1));
}
complex complex:: operator+ (const complex &obj){
    complex test;
    test.img = img + obj.img;
    test.rel = rel + obj.img;

    return test;
}

bool complex::operator== (const complex &obj){
    return((rel == obj.rel)&&(img == obj.img));
}

complex complex::operator- (const complex &obj){
    complex test;
    test.img = img-obj.img;
    test.rel = rel-obj.rel;

    return test;
}

complex complex::operator* (const complex &obj){
    complex test;
    test.rel = (rel*obj.rel)-(img*obj.img);
    test.img = (img * obj.rel + rel*obj.img);
    return test;
}
void complex::operator= (const complex &obg){
    rel=obg.rel;
    img=obg.img;
};

void complex::set_complex(int rel1, int img1){
    rel = rel1;
    img = img1;
}
