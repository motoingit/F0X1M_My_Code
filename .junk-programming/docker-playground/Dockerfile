# instruction go here if you diddnt know what to do with this file, you can ask chatgpt for help or you can read the documentation of docker to learn how to use it. This file is used to build a docker image for your application, it contains instructions on how to build the image and what to do when the container is run.

#* Useses node version 22 as our base image

FROM node:22

#*goes to the app directior (cd terminal command)
WORKDIR /app

#* Copy pakage.json and package-lock.json to the working directory
COPY package*.json ./

#* Install the dependencies specified in package.json
RUN npm install

#* Copy all the files from the current directory to the working directory in the container
COPY . .

#* Set the environment variable PORT to 3000, which is the port our application will run on
ENV PORT=3000


EXPOSE 9000

#* why not RUN npm start? because we want to use CMD to specify the command that will be run when the container is started, this allows us to override the command if we want to run a different command when starting the container.
CMD ["npm", "start"]
