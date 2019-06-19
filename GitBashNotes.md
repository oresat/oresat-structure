# Using Git Bash for the SolidWorks

## first time setup
- `git clone` =  to copy the repo
- `git checkout -b branchname` = This creates a branch “dev_yourname” like “dev_joe” and switches you to that branch. This branch is a complete clone of master.
  
## Now go make things, do work in SolidWorks, etc

## Once you’re ready to check in
- Fully save everything in solidworks - please do shutdown SolidWorks.
- `git status`=  Shows what’s new, modified, etc. You’ll have red (modified and untracked), and changes ready to to commit are green.
- `git add filename1 filename2` = add file to commit
    - `git add .` =  Only if you want to add all the changes in the directory
- `git status` =  Everything should be green now, except for the files you don’t want to commit.
- `git commit -m “commit message”`
- `git status` =  Now it should say you’re ahead of master by one commit
- `git push` =  When you’re ready, do a git push, which saves your branch to the server.

## Once you’re ready to merge with master
- `git checkout master` = swap to master branch
- `git pull` = update master.
- `git checkout branchname` = swap back to your branch
- `git merge master` =  This merges master back in your branch.
- Now re-open everything in solidworks, make sure there’s nothing broken.
- `git checkout master` = swap to master branch again
- `git merge branchname` = merge your branch into master
- `git push` = push to remote
- Now you’re done, you can stay on master, but better would be to switch back to your branch
- `git checkout branchname` = swap back to your branch

