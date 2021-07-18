## Git 学习

#### 原理

![image-20210714123701498](C:\Users\54473\AppData\Roaming\Typora\typora-user-images\image-20210714123701498.png)

origin是可理解为远程仓库链接的别名

#### 基本操作

git init 

git add <文件内容>

git commit -m "代码提交信息"   

> git commit -am "代码提交信息" 可省略git add . 步骤

git push <远程仓库名（默认origin）> <分支（GitHub默认main，Git默认master，注意切换）>

git status(参数为-s  表示简短输出)   查看文件修改

git diff <文件> （不加参数默认比较工作区和暂存区 加--cached比较暂存区与最新本地版本库 加HEAD比较工作区与最新本地版本库 也可以加commit-id比较与指定commit差异）

git log   (查看历史版本 按q键退出查看)

git restore --worktree <文件>  （如果暂存区有该文件修改，则恢复到与暂存区一致，如果没有，则恢复到最近的提交一致。 --worktree 可省略）

git restore --staged <文件> （将修改从暂存区撤出）

git restore --source=<commit-id>（将工作区内容切换到某个commit版本）

git reflog (记录所有操作)

git rm <文件名> 删除文件（若只删除缓存区文件 而不删除工作区文件 则使用 git rm --cached <文件名>）

git branch (查看所有分支)
git branch -d <分支名> （删除分支）

git switch <分支名> (切换分支)

git switch -c <分支名> （创建一个新分支并切换到该新分支）

git fetch  <远程仓库 如：origin> 获取更新代码

git stash 将当前工作目录中的修改存储，可随时应用

