.DEFAULT_GOAL := git
m ?= arson
git:
	mv ./book/ ./docs/
	git add -A
	git commit -m "$m"
	git push origin main

