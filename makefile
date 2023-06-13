.DEFAULT_GOAL := git
m ?= arson
git:
	mdbook clean
	rm -rf ./docs/
	mdbook build
	mv ./book/ ./docs
	cp -r ./docs/* ../pages/
	git add -A
	git commit -m "$m"
	git push origin main

