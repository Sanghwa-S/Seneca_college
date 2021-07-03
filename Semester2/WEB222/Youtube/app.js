// List of videos in the system
const videosList = [
    {
      "title": "The Hand Ripped Noodles Everyone Should Know How to Make",
      "author": "Ethan Chlebowski",
      "description": "This dish is known as Hot oil-seared Biang Biang noodles. The noodles are stretched than bounced on the work surface.",
      "views": "123K views",
      "date_posted": "1 day ago",
      "profile_photo": "assets/profiles/ethan.jpg",
      "video_thumbnail": "assets/hand-pulled-noodles.jpg",
      "link": "https://www.youtube.com/watch?v=UBxNd-E2sP0"
    },
    {
      "title": "Making Potato Chips At Home",
      "author": "My Name is Andong",
      "description": "Classic potato chips or Kettle Style potato chips - no matter what your favorite is, with this home made potato chips recipe your success is guaranteed. But did you know the story and science behind potato chips?",
      "views": "693K views",
      "date_posted": "4 months ago",
      "profile_photo": "assets/profiles/andong.jpg",
      "video_thumbnail": "assets/potato-chips.jpg",
      "link": "https://www.youtube.com/watch?v=UiJmmVd3kWI"
    },
    {
      "title": "Uncle Roger HATE Jamie Oliver Egg Fried Rice",
      "author": "mrnigelng",
      "description": "Jamie Oliver came up with an egg fried rice recipe. Uncle Roger don't like. Niece and nephew, if you want to see Uncle Roger collab with Jamie, please tweet at him and DM him on instagram. Tell him to be in Uncle Roger video!",
      "views": "14M views",
      "date_posted": "7 months ago",
      "profile_photo": "assets/profiles/nigel.jpg",
      "video_thumbnail": "assets/fried-rice.jpg",
      "link": "https://www.youtube.com/watch?v=t_KdbASIkB8"
    },
    {
      "title": "Easy laksa at home... in just 15 minutes! 🙌💯🙌💯 Marion's Kitchen",
      "author": "Marion's Kitchen",
      "description": "My easy laksa curry recipe is perfect for when that noodle soup craving hits hard. Ready in 15 minutes!",
      "views": "651K views",
      "date_posted": "3 months ago",
      "profile_photo": "assets/profiles/marion.jpg",
      "video_thumbnail": "assets/laksa.jpg",
      "link": "https://www.youtube.com/watch?v=ssOi5GudOX0"
    },
    {
        "title": "3 Dollar Homemade Ramen | But Cheaper",
        "author": "Joshua Weismann",
        "description": "No, this isn't instant noodles so don’t ask. I'm talking about the gourmet noodles that costs $15 or more for a single bowl! That's just unacceptable so I'll show you how to make homemade gourmet miso ramen for just 3 dollars that'll make all categories of ramen from fancy to instant look bad. ",
        "views": "575K views",
        "date_posted": "1 week ago",
        "profile_photo": "assets/profiles/joshua.jpg",
        "video_thumbnail": "assets/ramen.jpg",
        "link": "https://www.youtube.com/watch?v=vHvwUEHcyvA"
    },
    {
        "title": "6 New Ways To Enjoy Potato Recipes",
        "author": "Aaron and Claire",
        "description": "6 New Ways To Enjoy Potatoes Recipes! 1. Braised Potatoes 2. Stir-Fried Potatoes 3. Korean Potato Pancake (Gamja Jeon) 4. Accordion Potato 5. Potato Cheese Ball 6. Potato Croquette",
        "views": "1.6M views",
        "date_posted": "8 months ago",
        "profile_photo": "assets/profiles/aaron.jpg",
        "video_thumbnail": "assets/aaron-potatoes.jpg",
        "link": "https://www.youtube.com/watch?v=8IG3mDveIsQ"
      },
      {
        "title": "😋 Char Siu (叉燒) - My dad's recipe for Chinese BBQ Pork!",
        "author": "Made with Lau",
        "description": "Watch Daddy Lau teach us how to make char siu! Also known as Chinese BBQ Pork, this is a classic Cantonese dish that's extremely popular. If you’re new to char siu, it’s an extremely juicy, sweet, and savory pork dish, and it’s a popular entree on its own - and a pleasant addition to many different types of noodles, rice dishes, and pastries like cha siu bao.",
        "views": "499K views",
        "date_posted": "2 months ago",
        "profile_photo": "assets/profiles/lau.jpg",
        "video_thumbnail": "assets/pork.jpg",
        "link": "https://www.youtube.com/watch?v=zkCoAKTbHpQ"
      },
      {
        "title": "👶 Ginger Egg Fried Rice (姜炒饭) | The Secret Fried Rice Recipe, Without Soy Sauce!",
        "author": "Made with Lau",
        "description": "Watch Daddy Lau teach us how to make this healthy, easy Ginger Egg Fried Rice recipe! You can do without soy sauce for this recipe :) ",
        "views": "87K views",
        "date_posted": "9 months ago",
        "profile_photo": "assets/profiles/lau.jpg",
        "video_thumbnail": "assets/lau-fried-rice.jpg",
        "link": "https://www.youtube.com/watch?v=FBScXlydaa8"
      },
      {
        "title": "Oven Fries — CRISPIER Than Deep-Fried",
        "author": "Adam Ragusea",
        "description": "I suppose this is more of a techniques than a recipe. Take whatever potatoes you want. Peel them, or don't. Cut them into fry-like shapes, being sure to get roughly equal thickness, and cut them maybe twice as thick as you want them — they'll shrink a lot during cooking.",
        "views": "9M views",
        "date_posted": "1 year ago",
        "profile_photo": "assets/profiles/adam.jpg",
        "video_thumbnail": "assets/adam-potatoes.jpg",
        "link": "https://www.youtube.com/watch?v=m6kcANnAJSo"
      },
      {
        "title": "5 wholesome breakfast smoothies",
        "author": "Pick Up Limes",
        "description": "If you're feeling like you've got a hectic morning and you would otherwise be skipping breakfast then we've got smoothie recipe ideas for you.",
        "views": "1.9M views",
        "date_posted": "10 months ago",
        "profile_photo": "assets/profiles/pul.jpg",
        "video_thumbnail": "assets/smoothies.jpg",
        "link": "https://www.youtube.com/watch?v=7xw7HGS7PIw"
      }
  ]


// This function will automatically generate the HTML for a single video search result.
// The function accepts a Javascript dictionary that contains the properties of a video
function generateRowHTML(video) {
    return `<div class="video">
                <img class="thumbnail" src="${video.video_thumbnail}">
                <div class="info">
                    <p class="name"><a href="${video.link}">${video.title}</a></p>
                    <p class="stats">${video.views} *  ${video.date_posted}</p>
                    <p class="creator">
                        <img src="${video.profile_photo}"/>
                        <span> ${video.author}</span>
                    </p>                    
                    <p class="desc">${video.description}</p>                        
                </div>                
            </div>` 
}

// @TODO: Put your code here

function searchingVideo() 
{
  let What_I_typed = document.getElementById("txt-search").value.toLowerCase();
  document.getElementById("txt-search").value = "";  
  
  let What_I_searched = []; 

  if (What_I_typed === "") 
  {   
    alert("Please enter a keyword");
  } 
  
  else 
  {    
    videosList.forEach((video) => 
      {     
          if (video.description.toLowerCase().search(What_I_typed) !== -1) 
          {   
            What_I_searched.push(video);  
          }
      });
    
      if (What_I_searched.length > 0)  
      {   
        document.getElementById("results").innerHTML = "";
            
          What_I_searched.forEach((video) => 
            {    
                document.getElementById("results").innerHTML += generateRowHTML(video);
            });
      } 
    
      else 
      {       
        document.querySelector("#results").innerHTML=`<span>No videos found with the keyword ${What_I_typed}</span>`;
        document.querySelector("#txt-search").value="";  
      }
  }
}

function showAllVideos() 
{
  document.querySelector("#results").innerHTML="";
  
  for(let i=0;i<videosList.length;i++)
  {
      document.querySelector("#results").innerHTML+=generateRowHTML(videosList[i]);
  }
}


document.querySelector("#btn-show-all").addEventListener("click",showAllVideos);
document.querySelector("#btn-search").addEventListener("click", searchingVideo);


