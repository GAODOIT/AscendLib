package main

import (
    "fmt"
)

type Phone interface {
    call()
    ret_call() int
}

type NokiaPhone struct {
    Phone
}

func (nokiaPhone NokiaPhone) ret_call() int {
    var tmp = 10
    fmt.Println("I am Nokia, I can call you!")
    return tmp
}

type IPhone struct {
    Phone
}

func (iPhone IPhone) ret_call() int {
    var tmp = 11
    fmt.Println("I am iPhone, I can call you!")
    return tmp
}

func main() {
    var phone Phone
    
    phone = new(NokiaPhone)
    fmt.Println(phone.ret_call())

    phone = new(IPhone)
    fmt.Println(phone.ret_call())
}
