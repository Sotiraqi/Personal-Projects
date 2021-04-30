

class ParkingSpot
{
    ParkingSpot(isOccupated)
    {
        this.isOccupated = 0;
    }

    currentState() //determines if a parking spot will be used or not (0-unused, 1-occupated, 2-reservated)
    {
        ParkingSpot.isOccupated = 1;
    }
}

function logIn(username, password)
{
    username = document.getElementById('form');
    console.log(username);
}

function requestParkingSpot(plates, time)
{
    plates = window.prompt("Please enter the plates");
    time = window.prompt("Please add estimated time of arrival");
    return `${plates} ${time}`;

}

var RepublikaParking = new Array();
var FanNoliParking = new Array();
var PazariParking = new Array();

for(var i = 0; i < 50; i++)
{
    RepublikaParking.push(new ParkingSpot);
}

for(var i = 0; i < 60; i++)
{
    FanNoliParking.push(new ParkingSpot);
}

for(var i = 0; i < 90; i++)
{
    PazariParking.push(new ParkingSpot);
}



