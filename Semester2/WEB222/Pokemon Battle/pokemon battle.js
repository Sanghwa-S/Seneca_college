// Define your Pokemon here.
class Pokemon {
    constructor(name, maxHP, currHP, attackPOWER, isDead) {
        // put your properties here
        this.name = name
        this.maxHP = maxHP
        this.currHP = currHP
        this.attackPOWER = attackPOWER
        this.isDead = true
    }
    // put your functions here
    attack(target)
    {
        console.log(`${this.name} attacks!`)
        let percentage = Math.random();
        if(percentage < 0.35){
            this.attackPOWER == 0
            return false;
        }
        else{
            return true;
        }
    }
    takeDamage(amt)
    {
        this.currHP -= amt;
        if(this.currHP <= 0)
        {
            this.currHP = 0;
            this.isDead = false;
        }
        console.log(`${this.name} takes ${amt} damage!\n`)
    }
    displayStats()
    {
        console.log(`   ${this.name}: ${this.currHP}/${this.maxHP} HP`)
    }
}

function displayGameOverMessage(pokemonA, pokemonB) {
    // 1. Display "BATTLE OVER!"
    console.log("BATTLE OVER!");
    // 2. Display the name of the winning pokemon
    if(pokemonA.currHP === 0){
        console.log(`${pokemonB.name} wins!\n`);
    }
    else
        console.log(`${pokemonA.name} wins!\n`);
    
    // 3. Display the hp for p1 and p2
    pokemonA.displayStats();
    pokemonB.displayStats();
}

function startBattle(){
    
    // 1. Create two pokemon

    const pokemonA = new Pokemon("Pikachu", 20, 20, 5, true);
    const pokemonB = new Pokemon("Butterfree", 30, 30, 3, true);
    
    // 2. Output the BATTLE START meesage
    console.log("BATTLE START!");
    console.log(`${pokemonA.name} (${pokemonA.maxHP}HP) vs. ${pokemonB.name} (${pokemonB.maxHP}HP)`)
    // 3. Alternate between the pokemon attacking
    // 3a.  Pokemon 1 should attempt to attack Pokemon 2.  (use the attack() class function)
    //  - If successful, then Pokemon 2 takes damage. (use the takeDamage() class function)
    //  - If not, then no damage applied
    
    // 3b.  Check if Pokemon 2 is still alive. If yes, continue. If no, game over! (use the isDead property)

    // 3c.  Pokemon 2 should attempt to attack Pokemon 1 (use the attack() class function)
    // - If successful, then Pokemon 1 takes damage (use the takeDamage() class function)
    // - If not, then no damage applied
   
    // 3d.  Check if Pokemon 1 is still alive. If yes, continue. If no, game oer (use the isDead property)
    while(pokemonA.isDead === true && pokemonB.isDead === true)
    {
    if(pokemonA.attack() === true)
    {
        pokemonB.takeDamage(pokemonA.attackPOWER)
        if(pokemonB.currHP > 0)
        {
            pokemonA.displayStats()
            pokemonB.displayStats()
            console.log("\n")   
        }

    }
    else{
        console.log(`${pokemonA.name} misses!`)
        console.log("\n") 
        pokemonA.displayStats()
        pokemonB.displayStats()
        console.log("\n")
    }
    if(pokemonB.isDead === false)
    {
        console.log(`${pokemonB.name} fainted!\n`)
        return displayGameOverMessage(pokemonA, pokemonB);
    }

    if(pokemonB.attack() === true)
    {
        pokemonA.takeDamage(pokemonB.attackPOWER)
        if(pokemonA.currHP > 0)
        {
            pokemonA.displayStats()
            pokemonB.displayStats()
            console.log("\n")   
        }
    }
    else{
        console.log(`${pokemonB.name} misses!`)
        console.log("\n") 
        pokemonA.displayStats()
        pokemonB.displayStats()
        console.log("\n")
    }
    if(pokemonA.isDead === false)
    {
        console.log(`${pokemonA.name} fainted!\n`)
        return displayGameOverMessage(pokemonA, pokemonB);
    }
        
    }
    

    // 4. At some point, one of the pokemon will be dead! Display the game over message! 
    
}

startBattle()