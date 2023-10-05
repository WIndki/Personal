'git init' //新建git库
'git add $file' //将目录下$file文件放入到提交缓冲区
'git commit -m 'TheNameOfCommit' ' //创建一次提交
'git remote add origin git@github.com:WIndki/Personal.git' //链接远程主机
'git push -u origin main' //提交 -f强制提交
本机命令，生成公钥：ssh-keygen -t rsa -C "*@*.com"  邮箱可以任意填写
本机命令，查看公钥：cat ~/.ssh/id_rsa.pub   查看之后然后copy
github线上添加公钥：项目仓库 => settings => SSH and GPG keys => New SSH key 