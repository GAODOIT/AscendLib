require 'net/http'                  # 我们需要的库
#host = 'www.ifeng.com'           #  web 服务器
#path = '/'                 # 我们想要的文件 

=begin
http = Net::HTTP.new("www.baidu.com", 80)          # 创建连接
headers, body = http.get("/") # 请求文件
p headers.code
p headers.message
p headers.class.name
print headers
=end
#p body
#
#puts Net::HTTP.get('www.baidu.com', '/') # => String
require 'net/http'
Net::HTTP.version_1_2   # 设定对象的运作方式

response = nil
Net::HTTP.start('www.baidu.com', 80) { |http|
    response = http.head( '/' )
    #response = http.get('/')
    #puts response.code
    #puts response.message
    #puts response['date']
    #puts response.body
}
p response['date']
p response['content-type']

require "open-uri"  

=begin
#如果有GET请求参数直接写在URI地址中  
uri = 'http://www.baidu.com'  
html_response = nil  
open(uri) do |http|  
  html_response = http.read  
end  
puts html_response  

if headers.code == "200"            # 检测状态码
    print body                        
else                                
    puts "#{headers.code} #{headers.message}" 
end
=end
