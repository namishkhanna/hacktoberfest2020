function Main{
	$towers=New-TowersOfHanoi
	$towers.Solve(5)
}
function New-TowersOfHanoi{ 
    New-Module -ArgumentList $numDisks,$source,$dest,$temp  -AsCustomObject { 
		$script:counter=0
		function Solve($numDisks, $source="Source",$dest="Dest",$temp="Temp") { 	
			if ($script:counter -eq 0){
				$htSpindleNames=@{"$source"=0;"$dest"=1;"$temp"=2}
				$spindleNames=$htSpindleNames.GetEnumerator() | sort Value | select -ExpandProperty Name
				$totalNumDisks=$numDisks
				$spindles=New-Object Collections.ArrayList
				foreach ($num in 1..3){
					$spindles.Add((new-object System.Collections.Stack)) | Out-Null
				}
				#initialize first spindle
				for ($disk=$numDisks*2;$disk -gt 0;$disk-=2){
				 	$spindles[0].Push((('_' * $disk) + "|" + ('_' * $disk)))
				}
				DrawTowers $totalNumDisks $spindles $spindleNames
			}
			$script:counter++
		    if ($numDisks -eq 1) { 
				$spindles[$htSpindleNames["$dest"]].Push($spindles[$htSpindleNames["$source"]].Pop())
				DrawTowers $totalNumDisks $spindles $spindleNames
		        Write-verbose "Move top disk from spindle $source to spindle $dest" 
				
		    } 
		    else 
		    { 
		        Solve ($numDisks - 1) $source $temp $dest
		        Solve 1 $source $dest $temp
		        Solve ($numDisks - 1) $temp $dest $source 
		    } 
		} 
		function DrawTowers($numDisks,$spindles,$spindleNames){
			if ($script:counter -eq 0){
				$totalNumDisks=$numDisks
			}
			#clone the stacks
			$spindleArray=New-Object Collections.ArrayList
			foreach ($num in 0..2){
				$spindleArray.Add($spindles[$num].Clone()) | Out-Null
			}
			#draw the towers
			$output=@()
			$revIndex=$totalNumDisks-1
			foreach ($index in (0..($totalNumDisks-1))){
				$ht=@{}
				$htFormat=@{}
				foreach ($spindleIndex in (0..2)){
					if ($spindleArray[$spindleIndex].Count -gt $revIndex){
						$ht.Add($spindleNames[$spindleIndex],$spindleArray[$spindleIndex].Pop())
					}
					else{ $ht.Add($spindleNames[$spindleIndex],"|") }
				}
			 	$output+=new-object PSObject -Property $ht
				$revIndex--
			}
			$source,$dest,$temp=$spindleNames
			$output  | ft -Property @{n="$source";e={$_.$source};a="Center"},@{n="$dest";e={$_.$dest};a="Center"},@{n="$temp";e={$_.$temp};a="Center"}
			
		}
	}
}

. Main