
param (
	[Parameter(Mandatory)][string]$OutDir
)

try {
	New-Item -ItemType Directory -Force -Path "../common/include/" | Out-Null
	Copy-Item "$OutDir/InfinityLoaderCommon.lib" "../common"
	Copy-Item "Common Headers/*" "../common/include" -Recurse -Force
}
catch {
	Write-Output $_; Exit -1
}
