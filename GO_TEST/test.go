package main

import (
    "time"
    "fmt"
)

func main() {
    /*这是我的第一个程序*/
    fmt.Println("Hello, World!")
    //var now_time time.Time
    fmt.Println(time.Now())

    fmt.Println(time.Now().IsZero())
    
}
