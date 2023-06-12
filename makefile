.DEFAULT_GOAL := git
m ?= arson
git:
	git add -A
	git commit -m "$m"
	git push origin main

