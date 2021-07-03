// Here is a list of all the people that will be displayed to the user
// You are NOT permitted to modify this variable or its contents.
const profilesList =[
    {image: "assets/profiles/harold.jpg", name: "Harold", age:"65", occupation: "Golf Expert"},
    {image: "assets/profiles/barbara.jpg", name: "Barbara", age:"24", occupation: "Designer"},
    {image: "assets/profiles/james.jpg", name: "James", age:"25", occupation: "MD Student"},
    {image: "assets/profiles/john.jpg", name: "John", age:"23", occupation: "Engineer"},
    {image: "assets/profiles/linda.jpg", name: "Linda", age:"23", occupation: "Software engineer"},
    {image: "assets/profiles/liz.jpg", name: "Liz", age:"25", occupation: "Photographer"},
    {image: "assets/profiles/mary.jpg", name: "Mary", age:"24", occupation: "High school teacher"},
    {image: "assets/profiles/michael.jpg", name: "Michael", age:"27", occupation: "Freelancer"},
    {image: "assets/profiles/patricia.jpg", name: "Patricia", age:"26", occupation: "Engineer"},
    {image: "assets/profiles/robert.jpg", name: "Robert", age:"30", occupation: "Physician"},
]

// This is a mandatory function and should not be removed.
function updateProfileUI() {
    // @TODO: This function should contain the code to update the profile section of the user interface.
    // You are permitted to modify the function parameters, but NOT the name of the function.

    //const clickedElement = event.target
    let profileImg = document.querySelector("div.profile").querySelector("img");
    let profName = document.querySelector(".name");
    let profAge = document.querySelector(".age");
    let profOccupation = document.querySelector(".occupation");
    let index;
    
    let flag = true;

    const errMsg = document.querySelector('#error');

    for(let i = 0; i < profilesList.length && flag; i++)
        {
	        if(profilesList[i].name === profName.innerText)
            {
                index = i;
                flag = false;
            }
        }
    
    //if(clickedElement.classList.contains("#btn-like") === true)
    if(this.id === 'btn-like')
    {
        if(index === 9)
        {
            alert("There's no more matching profiles!")
        } 
        else 
        {
            profileImg.src = profilesList[index+1].image;
            profName.innerHTML = profilesList[index+1].name;
            profAge.innerHTML = profilesList[index+1].age;
            profOccupation.innerHTML = profilesList[index+1].occupation;            
        }
    }

    else if(this.id === 'btn-rewind')
    {
        if(index === 0)
        {
            alert("You are at the beginning of the list.")
        } 
        else 
        {
            profileImg.src = profilesList[index-1].image;
            profName.innerHTML = profilesList[index-1].name;
            profAge.innerHTML = profilesList[index-1].age;
            profOccupation.innerHTML = profilesList[index-1].occupation;            
        }
    }
    
    else if(this.id ==='btn-nope')
    {

        if(!(profilesList[index+1]))
        {
            document.querySelector(".container").classList.add("hidden")
            errMsg.classList.remove('hidden');
        }
        else
        {
            profileImg.src = profilesList[index+1].image;
            profName.innerHTML = profilesList[index+1].name;
            profAge.innerHTML = profilesList[index+1].age;
            profOccupation.innerHTML = profilesList[index+1].occupation;
            profilesList.splice(index,1);
        }
        // console.log(`profileList length ${profilesList.length}`);
        // console.log(`profileList length ${profilesList[index+1]}`);
    }
}
document.querySelector("#btn-rewind").addEventListener("click",updateProfileUI);
document.querySelector("#btn-like").addEventListener("click",updateProfileUI);
document.querySelector("#btn-nope").addEventListener("click",updateProfileUI)


function premiumAD()
{
    const premiumImage = document.querySelector("div#premium");
    document.querySelector("div#premium").classList.remove("hidden");
    //console.log(premiumImage);
    setTimeout(function(){premiumImage.classList.add("hidden")}, 1000);
}
document.querySelector("#btn-boost").addEventListener("click",premiumAD);
document.querySelector("#btn-superlike").addEventListener("click",premiumAD);