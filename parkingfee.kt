fun main(args: Array<String>) {



    var hours = readLine()!!.toInt()

    var total : Double

    if (hours <= 5) {

        

        total  = (1.0* hours)

    

    println(total)

        return

        

        }

        

    else if ((hours > 5)&&(hours <24))

    {

   

        total = ((hours-5)*0.5)+ 5.0

        println(total)

        return 

    }

        

    else if (hours >=24)

    {

            total =  ((hours -24)*0.5) + 15.0

            println(total)

            return 

     }                  

     

   }        

              



