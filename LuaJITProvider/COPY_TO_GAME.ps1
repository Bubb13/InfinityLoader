
param (
	[Parameter(Mandatory)][string]$OutDir,
	[Parameter(Mandatory)][string]$GamePath
)

try {
	if (($GamePath -ne ".") -and (Test-Path $GamePath)) {
		"LuaProvider.dll", "LuaProvider.pdb" | ForEach-Object {Copy-Item "$OutDir/$_" $GamePath}
	}
}
catch {
	Write-Output $_
	Exit -1
}
