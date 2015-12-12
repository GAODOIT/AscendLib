package main
import "fmt"

func main(){
    var countryCapitalMap map[string]string
    countryCapitalMap = make(map[string]string)

    countryCapitalMap["France"] = "Paris"
    countryCapitalMap["Italy"]  = "Rome"
    countryCapitalMap["Japan"]  = "Tokyo"
    countryCapitalMap["India"]  = "New Delhi"

    for country := range countryCapitalMap {
        fmt.Println("Capital of", country, "is", countryCapitalMap[country])
    }

    captial, ok := countryCapitalMap["United States"]
    fmt.Println("Capital of United States is", ok)  
    if(ok){
        fmt.Println("Capital of United States is", captial)  
    }else {
        fmt.Println("Capital of United States is not present") 
    }
}
