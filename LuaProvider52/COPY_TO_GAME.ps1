
param (
	[Parameter(Mandatory)][string]$OutDir,
	[Parameter(Mandatory)][string]$GamePath
)

try {
	if ($Env:DEPLOY -eq "1") {
		"LuaProvider.dll" | ForEach-Object {Copy-Item "$OutDir\$_" "$Env:DEPLOY_DIRECTORY\EEex\loader\Lua52\$_"}
		"LuaProvider.pdb" | ForEach-Object {Copy-Item "$OutDir\$_" "$Env:DEPLOY_DIRECTORY\pdb\Lua52\$_"}
	}
	if (($Env:USING_LUAJIT -ne "1") -and ($GamePath -ne ".") -and (Test-Path $GamePath)) {
		"LuaProvider.dll", "LuaProvider.pdb" | ForEach-Object {Copy-Item "$OutDir/$_" $GamePath}
	}
}
catch {
	Write-Output $_
	Exit -1
}
