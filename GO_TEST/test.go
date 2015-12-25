package main

import (
	"fmt"
)

/*
func main() {
    //这是我的第一个程序
    fmt.Println("Hello, World!")
    //var now_time time.Time
    fmt.Println(time.Now())
    fmt.Println(time.Now().IsZero())

}
*/
func main() {

	var a int

	var f float32

	var str string

	fmt.Print("准备录入数据：")

	fmt.Scanf("%d, %f, %s", &a, &f, &str) //录入数据

	fmt.Println("输出录入结果：", a, f, str)
}
